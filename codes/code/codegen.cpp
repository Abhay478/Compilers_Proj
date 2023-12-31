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

extern Claim * current_claim;
extern Scope * current_scope;
extern Scope * rule_scope;
extern Var * out;

vector<Var *> add_gen(string sum, string op1, string op2) {
    if(!current_claim) return {};
    rule_scope = current_scope;
    auto t = current_claim->type;
    if(current_claim->archetype != GROUP) {
        return {};
    }
    auto v1 = new Var(sum, t);
    auto v2 = new Var(op1, t);
    auto v3 = new Var(op2, t);
    current_scope->insert(v1);
    current_scope->insert(v2);
    current_scope->insert(v3);

    out = v1;

    string h = t->repr_cpp() + " operator+(" + t->repr_cpp() + " " + v2->repr_cpp() + ", " + t->repr_cpp() + " " + v3->repr_cpp() + ") ";
    generate(h);

    return {v1, v2, v3};
}

vector<Var *> mult_gen(string prod, string op1, string op2) {
    if(!current_claim) return {};
    rule_scope = current_scope;
    auto t = current_claim->type;
    Var * v1, * v2, * v3;
    if(current_claim->archetype == RING) {
        v1 = new Var(prod, t);
        v2 = new Var(op1, t);
        v3 = new Var(op2, t);
        current_scope->insert(v1);
        current_scope->insert(v2);
        current_scope->insert(v3);

        out = v1;

        string h = t->repr_cpp() + " operator*(" + t->repr_cpp() + " " + v2->repr_cpp() + ", " + t->repr_cpp() + " " + v3->repr_cpp() + ") ";
        generate(h);
    } else if(current_claim->archetype == SPACE) {
        auto over = current_claim->over;
        v1 = new Var(prod, t);
        v2 = new Var(op1, t);
        v3 = new Var(op2, over);
        current_scope->insert(v1);
        current_scope->insert(v2);
        current_scope->insert(v3);

        out = v1;

        string h = t->repr_cpp() +
            " operator*(" + t->repr_cpp()
            + " " + v2->repr_cpp() + ", "
            + over->repr_cpp() + " "
            + v3->repr_cpp() + ") ";
        generate(h);
    } else {
        return {};
    }

    return {v1, v2, v3};
}

Var * id_gen(string id, int val) {
    if(!current_claim) return NULL;
    rule_scope = current_scope;
    Type * t = current_claim->type;
    auto v = new Var(id, t);
    out = v;
    current_scope->insert(v);
    if(current_claim->archetype == GROUP) {
        if(val != 0) return NULL;
        string s = t->repr_cpp() + " " + t->repr_cpp() + "::zero() ";
        generate(s);
    }
    else if(current_claim->archetype == RING) {
        if(val != 1) return NULL;
        string s = t->repr_cpp() + " " + t->repr_cpp() + "::one() ";
        generate(s);
    }
    else {
        return NULL;
    }   
    return v;
}

vector<Var *> neg_gen(string neg, string op) {
    if(!current_claim) return {};
    rule_scope = current_scope;
    if(current_claim->archetype != GROUP) {
        return {};
    }
    Type * t = current_claim->type;
    auto v1 = new Var(neg, t);
    auto v2 = new Var(op, t);
    current_scope->insert(v1);
    current_scope->insert(v2);
    out = v1;
    string s = t->repr_cpp() + " " + "operator-("+ t->repr_cpp() + " " + v2->repr_cpp() +") ";
    generate(s);

    return {v1, v2};
}

vector<Var *> inv_gen(string inv, string op) {
    if(!current_claim) return {};
    rule_scope = current_scope;
    if(current_claim->archetype != FIELD) {
        return {};
    }
    Type * t = current_claim->type;
    auto v1 = new Var(inv, t);
    auto v2 = new Var(op, t);
    current_scope->insert(v1);
    current_scope->insert(v2);
    out = v1;
    string s = t->repr_cpp() + " " + t->repr_cpp() + "::inv(" + t->repr_cpp() + " " + v2->repr_cpp() + ") ";
    generate(s);

    return {v1, v2};
}

void claim_with(Archetypes a, Function * entry1, Function * entry2) {
    switch(a) {
        case GROUP: {
            auto v1 = add_gen("_sum", "_op1", "_op2");
            generateln("{"); indent++;
            string s = v1[0]->repr_cpp() + " = " + entry1->repr_cpp() + "(" + entry2->repr_cpp() + "(" + v1[1]->repr_cpp() + ") + " + entry2->repr_cpp() + "(" + v1[2]->repr_cpp() + "));";
            generateln(s);
            s = "return " + v1[0]->repr_cpp() + ";";
            generateln(s);
            indent--;
            generateln("}");

            auto v2 = neg_gen("_neg", "_op");
            generateln("{"); indent++;
            s = v2[0]->repr_cpp() + " = " + entry2->repr_cpp() + "(-" + entry1->repr_cpp() + "(" + v2[1]->repr_cpp() + "));";   
            generateln(s);
            s = "return " + v2[0]->repr_cpp() + ";";
            generateln(s);
            indent--;
            generateln("}");

            auto v3 = id_gen("_id", 0);
            generateln("{"); indent++;
            s = v3->repr_cpp() + " = " + entry1->repr_cpp() + "(0)" + ";";
            generateln(s);
            s = "return " + v3->repr_cpp() + ";";
            generateln(s);
            indent--;
            generateln("}");

            break;
        }
        case RING: {
            auto v4 = mult_gen("_prod", "_op1", "_op2");
            generateln("{"); indent++;
            string s = v4[0]->repr_cpp() + " = " + entry1->repr_cpp() + "(" + entry2->repr_cpp() + "(" + v4[1]->repr_cpp() + ") * " + entry2->repr_cpp() + "(" + v4[2]->repr_cpp() + "));";
            generateln(s);
            s = "return " + v4[0]->repr_cpp() + ";";
            generateln(s);
            indent--;
            generateln("}");

            auto v5 = id_gen("_id", 1);
            generateln("{"); indent++;
            s = v5->repr_cpp() + " = " + entry1->repr_cpp() + "(1)" + ";";
            generateln(s);
            s = "return " + v5->repr_cpp() + ";";
            generateln(s);
            indent--;
            generateln("}");

            break;
        }
        case FIELD: {
            auto v6 = inv_gen("_inv", "_op");
            generateln("{"); indent++;
            string s = v6[0]->repr_cpp() + " = " + entry1->repr_cpp() + "(" + entry2->return_type->repr_cpp() + "::inv(" + entry2->repr_cpp() + "(" + v6[1]->repr_cpp() + ")));";
            generateln(s);
            s = "return " + v6[0]->repr_cpp() + ";";
            generateln(s);
            indent--;
            generateln("}");

            break;
        }
        case SPACE: {
            auto v7 = mult_gen("_prod", "_op1", "_op2");
            generateln("{"); indent++;
            string s = v7[0]->repr_cpp() + " = " + entry1->repr_cpp() + "(" + entry2->repr_cpp() + "(" + v7[1]->repr_cpp() + ") * " + entry2->repr_cpp() + "(" + v7[2]->repr_cpp() + "));";
            generateln(s);
            s = "return " + v7[0]->repr_cpp() + ";";
            generateln(s);
            indent--;
            generateln("}");
            break;
        }
        default:
            break;
    }
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
            auto t = func->return_type->repr_cpp() + " m_" + func->name + "(";
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
                    auto zero = "static " + sste->name + " zero();";
                    generateln_h(zero);
                    break;
                }
                case RING: {
                    auto one = "static " + sste->name + " one();";
                    generateln_h(one);
                    break;
                }
                case FIELD: {
                    auto div = "static " + sste->name + " inv(" + sste->name + ");";
                    generateln_h(div);
                    break;
                }
                case SPACE: {
                    break;
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
        auto s = "enum class " + este->name + " {";
        generateln_h(s);
        indent++;
        for (auto vste : este->fields) {
            auto t = vste + ",";
            generateln_h(t);
        }
        for(auto claim : este->claimd) {
            switch(claim) {
                case GROUP: {
                    auto zero = este->name + " zero();";
                    generateln_h(zero);
                    break;
                }
                case RING: {
                    auto one = este->name + " one();";
                    generateln_h(one);
                    break;
                }
                case FIELD: {
                    auto div = "static " + este->name + " inv(" + este->name + ");";
                    generateln_h(div);
                    break;
                }
                case SPACE: {
                    break;
                }
            }
        }
        
        indent--;
        generateln_h("};");
        generateln_h("");
    }
}
