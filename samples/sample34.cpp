// Include the headers
#include "blocks/c_code_generator.h"
#include "builder/static_var.h"
#include "builder/dyn_var.h"
#include <iostream>

// Include the BuildIt types
using builder::dyn_var;
using builder::static_var;
static void bar(void) {
     // Insert code to stage here
     dyn_var<int> x = 5;
     for (dyn_var<int> i = 0; i < 100; i = i + 1) {
         if (i == x) {
             x = i;
             break;
         }
     }
}

int main(int argc, char* argv[]) {
	builder::builder_context context;
	auto ast = context.extract_function_ast(bar, "bar");
	ast->dump(std::cout, 0);
	block::c_code_generator::generate_code(ast, std::cout, 0);
}


