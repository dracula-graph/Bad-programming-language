#include <string>
#include <vector>

#include "../const.h"
#include "bad_parser.h"

statement::varType parseVarType(const std::string& s) {
    if (s == "I16") return statement::varType::I16_type;
    if (s == "I32") return statement::varType::I32_type;
    if (s == "F16") return statement::varType::F16_type;
    if (s == "F32") return statement::varType::F32_type;
    if (s == "S16") return statement::varType::S16_type;
    if (s == "S32") return statement::varType::S32_type;

    throw std::runtime_error("Unknown variable type: " + s);
}

std::vector<statement> bad_parser(std::vector<token>& lexer_tokens){

    std::vector<statement> out_statment;
    size_t i = 0;

    while (i < lexer_tokens.size()) {

        const auto& tok = lexer_tokens[i];

        switch (tok.type) {
            case TokenType::Identifier: {
                if (tok.value == "PRINT" ||tok.value == "BOUT" ) {

                    i++;
                    if (i >= lexer_tokens.size() || lexer_tokens[i].type != TokenType::QuoteText)
                        throw std::runtime_error("Not quotes after PRINT");


                    std::string text = lexer_tokens[i].value;
                    i++;

                    if (i >= lexer_tokens.size() || lexer_tokens[i].type != TokenType::Semicolon)
                        throw std::runtime_error("Not semicolon ; after PRINT");

                    i++;

                    out_statment.push_back({
                        statement::Command_Type::Print,
                        "",
                        text,
                        statement::varType::S16_type
                    });
                    continue;

                }
                if (tok.value == "I16" || tok.value == "F16" || tok.value == "S16") {
                    std::string type = lexer_tokens[i].value;
                    i++;
                    std::string name = lexer_tokens[i].value;
                    i++;
                    std::string value = lexer_tokens[i].value;
                    i++;
                    if (i >= lexer_tokens.size() || lexer_tokens[i].type != TokenType::Semicolon)
                        throw std::runtime_error("Not semicolon ; after SET");
                    i++;

                    statement::varType vt = parseVarType(type);

                    out_statment.push_back({
                        statement::Command_Type::Declare,
                        name,
                        value,
                        vt
                    });
                    continue;

                }
                break;
            }
            case TokenType::Number: {

                break;
            }
            case TokenType::LParen: {
                if (lexer_tokens[i].value == "(") {
                    i++;
                    statement::Command_Type st;
                    if(lexer_tokens[i].value == "+"){
                        st = statement::Command_Type::sum;
                    } else if (lexer_tokens[i].value == "-") {
                        st = statement::Command_Type::div;
                    } else if (lexer_tokens[i].value == "*") {
                        st = statement::Command_Type::mult;
                    } else if (lexer_tokens[i].value == "/") {
                        st = statement::Command_Type::differ;
                    } else {
                        throw std::runtime_error("Not corrent command");
                    }
                    i++ ;
                    std::string first = lexer_tokens[i].value;
                    i++ ;
                    std::string last = lexer_tokens[i].value;
                    out_statment.push_back({
                        st,
                        first,
                        last,
                        statement::varType::I16_type
                    });
                    i++;
                    if (i >= lexer_tokens.size() || lexer_tokens[i].type != TokenType::RParen)
                        throw std::runtime_error("Not ) after (");
                    i++;
                    if (i >= lexer_tokens.size() || lexer_tokens[i].type == TokenType::Semicolon)
                        i++;
                    continue;
                }
                break;

            }
            case TokenType::RParen: {

                break;
            }
            case TokenType::QuoteText: {

                break;
            }
            case TokenType::Semicolon: {

                break;
            }
            case TokenType::Ampersand: {

                break;
            }
            case TokenType::Equals: {

                break;
            }
            case TokenType::DoubleEquals: {

                break;
            }
            case TokenType::End: {

                break;
            }
        }

    }

    return out_statment;

}
