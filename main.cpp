#include "crow.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

void lower(string &s) {
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            continue; 
        }
        ans += tolower(s[i]);
    }
    s = ans;
}

int main() {
    unordered_map<string, string> responses;
    responses["hi"] = "Hello 👋 How can I help you today?";
    responses["hello"] = "Hi there 😊";
    responses["hey"] = "Hey 👋 Nice to meet you!";
    responses["goodmorning"] = "Good Morning ☀️";
    responses["goodafternoon"] = "Good Afternoon 😊";
    responses["goodevening"] = "Good Evening 🌙";
    responses["howareyou"] = "I'm doing great 🚀";
    responses["yourname"] = "I am a deterministic rule-based AI assistant created by Krish Goel.";
    responses["whoareyou"] = "I am a deterministic rule-based AI assistant created by Krish Goel.";
    responses["whocreatedyou"] = "I was created by Krish Goel 😎";
    responses["whatcanyoudo"] = "I can answer predefined questions and chat with you!";
    responses["help"] = "Try asking greetings, jokes, motivation or chatbot info.";
    responses["motivateme"] = "Success starts with self-belief 💪";
    responses["inspireme"] = "Push yourself because nobody else will do it for you 🚀";
    responses["tipsforsuccess"] = "Stay consistent, disciplined and keep learning daily 💯";
    responses["studytips"] = "Study in small focused sessions with proper breaks 📚";
    responses["gymmotivation"] = "Train like a beast 💪 Results take time.";
    responses["tellmeajoke"] = "Why do programmers hate nature? Because it has too many bugs 😂";
    responses["funfact"] = "Python was named after Monty Python, not the snake 😄";
    responses["iamsad"] = "Don't worry ❤️ Better days are coming.";
    responses["iamhappy"] = "That's amazing 😍 Keep smiling!";
    responses["iamtired"] = "Take some rest 😴 You deserve it.";
    responses["whatisai"] = "AI stands for Artificial Intelligence.";
    responses["whatismachinelearning"] = "Machine Learning enables systems to learn from data.";
    responses["whatisdeeplearning"] = "Deep Learning is a subset of Machine Learning using neural networks.";
    responses["whatischatbot"] = "A chatbot is a software application that simulates conversation.";
    responses["whatispython"] = "Python is a popular programming language.";
    responses["whatisflask"] = "Flask is a lightweight Python web framework.";
    responses["whatisprogramming"] = "Programming is the process of creating software using code.";
    responses["whatiscoding"] = "Coding means writing instructions for computers.";
    responses["whatishtml"] = "HTML is used to structure web pages.";
    responses["whatiscss"] = "CSS is used for styling websites.";
    responses["whatisjavascript"] = "JavaScript adds functionality to websites.";
    responses["whatisfrontend"] = "Frontend is the visible part of a website.";
    responses["whatisbackend"] = "Backend handles server-side logic and databases.";
    responses["whatisdatascience"] = "Data Science is extracting insights from data.";
    responses["howtobecomeaiengineer"] = "Learn Python, Machine Learning, Deep Learning and build projects 🚀";
    responses["howtobecomewebdeveloper"] = "Learn HTML, CSS, JavaScript and backend technologies.";
    responses["resumetips"] = "Keep your resume clean, short and project-focused.";
    responses["interviewtips"] = "Practice projects, communication and coding problems regularly.";
    responses["recommendmovie"] = "You should watch Interstellar 🚀";
    responses["bestactor"] = "There are many great actors, but everyone has their favorite 😄";
    responses["bestwebseries"] = "Breaking Bad is one of the highest-rated series.";
    responses["doyouloveme"] = "Of course ❤️ I love talking with you!";
    responses["areyoureal"] = "I am a virtual AI chatbot 🤖";
    responses["canyouthink"] = "I follow predefined rule-based logic.";
    responses["areyouintelligent"] = "I am intelligent within my programmed rules 😎";
    responses["portfolio"] = "My developer is building awesome AI projects 🚀";
    responses["github"] = "You can upload this project on GitHub for your portfolio.";
    responses["howisweather"] = "I cannot check live weather yet 🌤️";
    responses["favoritefood"] = "I don't eat food 😄 but pizza sounds amazing 🍕";
    responses["favoritesport"] = "Football and cricket are very popular ⚽🏏";
    responses["thankyou"] = "You're welcome 😊";
    responses["thanks"] = "Happy to help 🚀";

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Krish Goel's C++ AI Chatbot Web Engine is Online! Send messages via: /chat?msg=YOUR_INPUT";
    });

    CROW_ROUTE(app, "/chat")([responses](const crow::request& req){
        auto msg_param = req.url_params.get("msg");
        if (!msg_param) return crow::response("Bot: Please provide a message query parameter (?msg=...)");
        string st = string(msg_param);
        lower(st);
        if (st == "exit" || st == "bye" || st == "break") {
            return crow::response("Bot: Session ended 👋 Goodbye!");
        }
        auto it = responses.find(st);
        if (it != responses.end()) {
            return crow::response("Bot: " + it->second);
        } else {
            return crow::response("Bot: Sorry 😅 I don't understand that command yet. Please try saying 'hello' or 'help'.");
        }
    });

    char* port = getenv("PORT");
    uint16_t app_port = port ? (uint16_t)stoi(port) : 18080;
    app.bindaddr("0.0.0.0").port(app_port).multithreaded().run();
}