#include "semantic.hpp"
using namespace std;
bool last_ln = true;
extern FILE * output_stream;
extern FILE * struct_stream;
extern int indent;

void generate(const char *s) {
    if (last_ln) {
        for (int i = 0; i < indent; i++) {
            fprintf(output_stream, "    ");
        }
    }
    fprintf(output_stream, "%s", s);
    last_ln = false;
}

void generate(string &s) {
    generate(s.c_str());
}

void generateln(const char *s) {
    generate(s);
    fprintf(output_stream, "\n");
    last_ln = true;
}

void generateln(string &s) {
    generateln(s.c_str());
}

void generate_h(const char *s) {
    if (last_ln) {
        for (int i = 0; i < indent; i++) {
            fprintf(struct_stream, "    ");
        }
    }
    fprintf(struct_stream, "%s", s);
    last_ln = false;
}

void generate_h(string &s) {
    generate_h(s.c_str());
}

void generateln_h(const char *s) {
    generate_h(s);
    fprintf(struct_stream, "\n");
    last_ln = true;
}

void generateln_h(string &s) {
    generateln_h(s.c_str());
}

// So now, look through struct_st and enum_st and generate the appropriate code
void generate_structs() {
    for (auto sste : struct_st.entries) {
        if(sste->builtin) continue;
        auto s = "struct " + sste->name + " {";
        generateln_h(s);
        // printf("%s\n", sste->name.c_str());
        indent++;
        for (auto vste : sste->fields) {
            // printf("%s\n", vste->name.c_str());
            auto t = vste->type->repr_cpp() + " " + vste->name + ";";
            generateln_h(t);
        }
        // printf("out.\n");

        for(auto func : sste->methods->entries) {
            printf("func: %s\n", func->name.c_str());
            auto t = func->return_type->repr_cpp() + " " + func->name + "(";
            for(auto param : func->params->entries) {
                t += param->type->repr_cpp() + " " + param->name + ", ";
            }
            if(func->params->entries.size()) {
                t.pop_back();
                t.pop_back();
            }
            t += ");";
            generateln_h(t);
        }

        // empty constructor
        auto empty = sste->name + "() {}";
        generateln_h(empty);

        for(auto claim : sste->claimd) {
            switch(claim) {
                case GROUP: {
                    // auto add = sste->name + " operator+(const " + sste->name + " & other) const;";
                    // generateln_h(add);
                    // auto neg = sste->name + " operator-() const;";  
                    // generateln_h(neg);
                    auto zero = sste->name + " zero();";
                    generateln_h(zero);
                    break;
                }
                case RING: {
                    // auto mul = sste->name + " operator*(const " + sste->name + " & other) const;";
                    // generateln_h(mul);
                    auto one = sste->name + " one();";
                    generateln_h(one);
                    break;
                }
                case FIELD: {
                    auto div = "static " + sste->name + " inv(" + sste->name + ");";
                    generateln_h(div);
                    break;
                }
                case SPACE: {
                    // auto add = sste->name + " operator+(const " + sste->name + " & other) const;";
                    // generateln_h(add);
                    // TODO: Scalar multiplication
                    // auto mul = sste->name + " operator*(const " + sste. + " & other) const;";
                    // generateln_h(mul);
                }
            
            }
        }
        indent--;
        generateln_h("};");
        generateln_h("");
    }
}

void generate_enums() {
    for (auto este : enum_st.entries) {
        auto s = "enum " + este->name + " {";
        generateln_h(s);
        indent++;
        for (auto vste : este->fields) {
            auto t = vste + ",";
            generateln_h(t);
        }
        for(auto claim : este->claimd) {
            switch(claim) {
                case GROUP: {
                    auto add = este->name + " operator+(const " + este->name + " & other) const;";
                    generateln_h(add);
                    auto neg = este->name + " operator-() const;";  
                    generateln_h(neg);
                    break;
                }
                case RING: {
                    auto mul = este->name + " operator*(const " + este->name + " & other) const;";
                    generateln_h(mul);
                    break;
                }
                case FIELD: {
                    auto div = este->name + " inv() const;";
                    generateln_h(div);
                    break;
                }
                case SPACE: {
                    auto add = este->name + " operator+(const " + este->name + " & other) const;";
                    generateln_h(add);
                    // TODO: Scalar multiplication
                    // auto mul = este->name + " operator*(const " + este. + " & other) const;";
                    // generateln_h(mul);
                }
            
            }
        }
        
        indent--;
        generateln_h("};");
        generateln_h("");
    }
}
