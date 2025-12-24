#include <string>
#include <vector>

#include "bad_source_get.h"
#include "bad_lexer/bad_lexer.h"
#include "bad_parser/bad_parser.h"
#include "bad_compiler/bad_compiler.h"
#include "const.h"


int main(void){

    std::vector<std::string> file_data;
    std::vector<statement> parsed_ast;
    std::vector<token> file_tokens;
    std::string file_path;

    file_path = "main.bad";

    file_data = get_source_data(file_path);
    file_tokens = bad_lexer(file_data);

    // for (const auto& tok : file_tokens) {
    //     std::cout << "Token: " << tok.value << " type=" << (int)tok.type << std::endl;
    // }

    parsed_ast = bad_parser(file_tokens);

    bad_compiler(parsed_ast);

    return 0;
}
