#include <iostream>
#include <string>

struct Question {
    std::string question;
    std::string options[4];
    int correctOption;
};
     
 Question questions[] = {
    {"¿En qué temporada Twilight Sparkle se convierte en alicornio?", {"1", "3", "5", "6"}, 1},
    {"¿Cuál es el nombre de la hija de Shining Armor y Cadance?", {"Flurry Heart", "Scootaloo", "Pound Cake", "Cozy Glow"}, 0},
    {"¿A qué pony le corresponde el elemento de la honestidad?", {"Abuela Smith", "Rarity", "AppleJack", "Pinkie Pie"}, 2},
    {"¿Cuál es el villano de la primer temporada?", {"Rey Tormenta", "Nightmare Moon", "Sunset Shimmer", "Tempestad"}, 1},
    {"¿Cuál es el nombre de la princesa gobernante de Equestria?", {"Princesa Luna", "Princesa Cadance", "Princesa Celestia", "Big McIntosh"}, 2},
    {"¿Cuál es el nombre de la mascota de Fluttershy?", {"Winona", "Abuela Smith", "discord", "Angel"}, 3},
    {"¿Qué representa Twilight Sparkle como elemento de la armonía?", {"Lealtad", "Magia", "Generosidad", "Amistad"}, 1},
    {"¿Qué tipo de pony es Rainbow Dash?", {"Terrestre", "Pegaso", "Unicornio", "Dragón"}, 1},
    {"¿Cuál es el nombre del amigo dragón de Twilight Sparkle?", {"Spike", "Abuela Smith", "Blaze", "Draco"}, 0},
    {"¿Cómo se llama la reina de los cambiantes?", {"Reina Chrysalis", "Reina Novo", "Rey Sombra", "Cheerilee"}, 0}
};
void printQuestion(const Question& q) {
    std::cout << q.question << "\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << i + 1 << ". " << q.options[i] << "\n";
    }
}
bool askQuestion(const Question& q) {
    printQuestion(q);

    int userAnswer;
    std::cout << "Ingresa el número de la respuesta correcta (1-4): ";
    std::cin >> userAnswer;
    
    while (userAnswer < 1 || userAnswer > 4) {
        std::cout << "Opción inválida :( Ingresa el número de la respuesta correcta (1-4): ";
        std::cin >> userAnswer;
    }

    return (userAnswer - 1) == q.correctOption;
}
int startGame() {
    int score = 0;
    for (const auto& q : questions) {
        if (askQuestion(q)) {
            score++;
        }
    }
    return score;
}
void evaluateScore(int score) {
    int totalQuestions = sizeof(questions) / sizeof(questions[0]);
    float percentage = (static_cast<float>(score) / totalQuestions) * 100;

    std::cout << "\n¡Respondiste correctamente a " << score << " preguntas de " << totalQuestions << ". ";

    // Evaluar el puntaje y mostrar un mensaje correspondiente
    if (percentage >= 70) {
        std::cout << "¡Eres un experto en My Little Pony! :D";
    } else if (percentage >= 40) {
        std::cout << "¡No está mal, puedes mejorar! x_x";
    } else {
        std::cout << "muy mal :(";
    }

    std::cout << "\n";
}

int main() {
    std::cout << "Bienvenido al juego. Presiona '.' para empezar:\n";
    char start;
    std::cin >> start;
    
    if (start == '.') {
        std::cout << "Comencemos:\n";
        int finalScore = startGame();
        evaluateScore(finalScore);
    } else {
        std::cout << "Entrada incorrecta.\n";
    }

    return 0;
}