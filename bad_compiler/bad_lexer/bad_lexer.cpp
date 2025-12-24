#include <vector>
#include <string>

#include "../const.h"

std::vector<token> bad_lexer(std::vector<std::string>& file_data){

    std::vector<token> tokens;
    bool in_quotes = false;
    std::string quote_buffer;
    std::string buffer;

    for (const auto& text : file_data) {

        for (size_t i = 0; i < text.size(); i++) {

            char c = text[i];

            if (in_quotes) {
                if (c == '\"') {
                    tokens.push_back({TokenType::QuoteText, quote_buffer});
                    quote_buffer.clear();
                    in_quotes = false;
                } else {
                      quote_buffer += c;
                }
                continue;
            }

            if (isalnum(c) || c == '_') {
                buffer += c;
            }
            else {
                if (!buffer.empty()) {
                    tokens.push_back({TokenType::Identifier, buffer});
                    buffer.clear();
                }
                if (!isspace(c)) {
                    switch (c) {
                        case '(':
                            tokens.push_back({TokenType::LParen, "("});
                            break;
                        case ')':
                            tokens.push_back({TokenType::RParen, ")"});
                            break;
                        case ';':
                            tokens.push_back({TokenType::Semicolon, ";"});
                            break;
                        case '&':
                            tokens.push_back({TokenType::Ampersand, "&"});
                            break;
                        case '=':
                            tokens.push_back({TokenType::Equals, "="});
                            break;
                        case '+':
                            tokens.push_back({TokenType::Equals, "+"});
                            break;
                        case '-':
                            tokens.push_back({TokenType::Equals, "-"});
                            break;
                        case '*':
                            tokens.push_back({TokenType::Equals, "*"});
                            break;
                        case '/':
                            tokens.push_back({TokenType::Equals, "/"});
                            break;

                        case '\"':
                            in_quotes = true;
                            break;

                    }
                }

            }
        }

        if (!buffer.empty()) {
            tokens.push_back({TokenType::Identifier, buffer});
        }
    }

    return tokens;
}
