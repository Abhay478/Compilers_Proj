fn z(): Rational {
    return 0 as (Rational);
}

fn o(): Rational {
    return 1 as (Rational);
}

struct Vec2 {
    a: Rational,
    b: Rational
}

claim Vec2 is Group {
    (c = 0) => {
        c.a = z();
        c.b = z();
    }
    (c = p + q) => {
        c.a = p.a + q.a;
        c.b = p.b + q.b;
    }
    (c = -p) => {
        c.a = -p.a;
    }
}

claim Vec2 is Space {
    Field = Rational;
    (c = p * q) => {
       c.a = p.a * q;
       c.b = p.b * q;
    }
}

fn main(): i32 {
    let a: Vec<i32> = [1, 2, 3] as (Vec<i32>);
    let b: Vec<i32> = [4, 5, 6] as (Vec<i32>);
    let c: Vec<i32> = a + a; 
    let e: i32 = a @ b;
    print(e as (str));
    print(c as (str));
    let d: i32 = a[0];
    print(e as (str));

    let s: Vec2;
    s.a = 4 as (Rational);
    s.b = 7 as (Rational);

    let t: Vec2 = s * 4 as (Rational);
    print(t.a as (str));
    print(t.b as (str));
}
