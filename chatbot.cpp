#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// convert string to lowercase
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    string userInput;

    cout << "🤖 Welcome to Customer Support Chatbot!\n";
    cout << "Type 'exit' to end chat\n\n";

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        userInput = toLowerCase(userInput);

        if (userInput == "exit") {
            cout << "Bot: Thank you! Have a nice day 😊\n";
            break;
        }
        else if (userInput.find("order") != string::npos) {
            cout << "Bot: Your order will be delivered in 3-5 days.\n";
        }
        else if (userInput.find("return") != string::npos) {
            cout << "Bot: You can return products within 7 days.\n";
        }
        else if (userInput.find("delivery") != string::npos) {
            cout << "Bot: Delivery usually takes 3-5 working days.\n";
        }
        else if (userInput.find("contact") != string::npos) {
            cout << "Bot: You can contact us at support@example.com\n";
        }
        else if (userInput.find("hello") != string::npos || userInput.find("hi") != string::npos) {
            cout << "Bot: Hello! How can I help you?\n";
        }
        else {
            cout << "Bot: Sorry, I didn't understand. Can you rephrase?\n";
        }
    }

    return 0;
}
