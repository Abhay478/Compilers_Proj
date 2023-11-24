struct Foo {
    x: Rational
}

forge (a: i32) as (b: Rational) {

}

claim Foo is Group {
    (c = 0) => {
        c.x = 0 as (Rational);
    }
    (c = a + b) => {
        c.x = a.x + b.x;
    }
    (c = -a) => {
        c.x = -a.x;
    }
}

claim Foo is Ring {
    (c = 1) => {
        c.x = 1 as (Rational);
    }
    (c = a * b) => {
        c.x = a.x * b.x;
    }
}

claim Foo is Field {
    (c = 1 / a) => {
        c.x = 1 as (Rational) / a.x;
    }
}

fn main(): i32 {
    return 0;
}
