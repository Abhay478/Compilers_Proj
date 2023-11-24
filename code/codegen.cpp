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
        Type * t_in = t->pop_type();
        v1 = new Var(prod, t);
        v2 = new Var(op1, t_in);
        v3 = new Var(op2, t);
        current_scope->insert(v1);
        current_scope->insert(v2);
        current_scope->insert(v3);

        out = v1;

        string h = t->repr_cpp() + " operator+(" + t_in->repr_cpp() + " " + v2->repr_cpp() + ", " + t->repr_cpp() + " " + v3->repr_cpp() + ") ";
        generate(h);
    } else {
        return {};
    }

    return {v1, v2, v3};
}

Var * id_gen(string id, int val) {
    rule_scope = current_scope;
    Type * t = current_claim->type;
    auto v = new Var(id, t);
    out = v;
    current_scope->insert(v);
    if(current_claim->archetype == GROUP) {
        if(val != 0) {printf("Bad val.\n"); return NULL;}
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
    string s = t->repr_cpp() + " " + t->repr_cpp() + "::operator-() ";
    generate(s);

    return {v1, v2};
}

vector<Var *> inv_gen(string inv, string op) {
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


/* int add_gen(Var * sum, Var * op1, Var * op2) {
    rule_scope = current_scope;
    auto t = current_claim->type;
    if(current_claim->archetype != GROUP) {
        return 1;
    }
    current_scope->insert(sum);
    current_scope->insert(op1);
    current_scope->insert(op2);

    out = sum;

    string h = t->repr_cpp() + " operator+(" + t->repr_cpp() + " " + op1->repr_cpp() + ", " + t->repr_cpp() + " " + op2->repr_cpp() + ") ";
    generate(h);

    return 0;
}

int mult_gen(Var * prod, Var * op1, Var * op2) {
    rule_scope = current_scope;
    auto t = current_claim->type;
    if(current_claim->archetype == RING) {
        auto v1 = new Var(prod, t);
        auto v2 = new Var(op1, t);
        auto v3 = new Var(op2, t);
        current_scope->insert(v1);
        current_scope->insert(v2);
        current_scope->insert(v3);

        out = v1;

        string h = t->repr_cpp() + " operator*(" + t->repr_cpp() + " " + v2->repr_cpp() + ", " + t->repr_cpp() + " " + v3->repr_cpp() + ") ";
        generate(h);
    } else if(current_claim->archetype == SPACE) {
        Type * t_in = t->pop_type();
        auto v1 = new Var(prod, t);
        auto v2 = new Var(op1, t_in);
        auto v3 = new Var(op2, t);
        current_scope->insert(v1);
        current_scope->insert(v2);
        current_scope->insert(v3);

        out = v1;

        string h = t->repr_cpp() + " operator+(" + t_in->repr_cpp() + " " + v2->repr_cpp() + ", " + t->repr_cpp() + " " + v3->repr_cpp() + ") ";
        generate(h);
    } else {
        return 1;
    }

    return 0;
}

int id_gen(Var * id, int val) {
    rule_scope = current_scope;
    Type * t = current_claim->type;
    auto v = new Var(id, t);
    out = v;
    current_scope->insert(v);
    if(current_claim->archetype == GROUP) {
        if(val != 0) return 1;
        string s = t->repr_cpp() + " " + t->repr_cpp() + "::zero() ";
        generate(s);
    }
    else if(current_claim->archetype == RING) {
        if(val != 1) return 2;
        string s = t->repr_cpp() + " " + t->repr_cpp() + "::one() ";
        generate(s);
    }
    else {
        return 3;
    }   
}

int neg_gen(Var * neg, Var * op) {
    rule_scope = current_scope;
    if(current_claim->archetype != GROUP) {
        return 1;
    }
    Type * t = current_claim->type;
    auto v1 = new Var(neg, t);
    auto v2 = new Var(op, t);
    current_scope->insert(v1);
    current_scope->insert(v2);
    out = v1;
    string s = t->repr_cpp() + " " + t->repr_cpp() + "::operator-() ";
    generate(s);

    return 0;
}

int inv_gen(Var * inv, Var * op) {
    rule_scope = current_scope;
    if(current_claim->archetype != FIELD) {
        return 1;
    }
    Type * t = current_claim->type;
    auto v1 = new Var(inv, t);
    auto v2 = new Var(op, t);
    current_scope->insert(v1);
    current_scope->insert(v2);
    out = v1;
    string s = t->repr_cpp() + " " + t->repr_cpp() + "::inv(" + t->repr_cpp() + " " + v2->repr_cpp() + ") ";
    generate(s);

    return 0;
}
 */


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
