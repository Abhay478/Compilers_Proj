fn fib(n: u32) : [u64] {
    let a: u64 = 0;
    let b: u64 = 1;
    let out: [u64] = [a, b];
    for (let i: u32 = 2; i < n; i++) {
        let c: u32 = a + b;
        a = b;
        b = c;
    }

    return out;
}

struct two_tup {
    val: u64,
    aux: u64
}

claim two_tup is Group {
    (c = a + b) => {
        c.val = a.val + b.val;
        c.aux = a.aux + b.aux;
    }

    (c = 0) => {
        c.val = 0;
        c.aux = 0;
    }

    (b = -a) => {
        b.val = -a.val;
        b.aux = -a.aux;
    }
}

forge (a: two_tup) as (b: (u64, u64)) {
    b = (a.val, a.aux);
    // print("We are forging here.");
}

forge (a: (u64, u64)) as (b: two_tup) {
    b.val = a.0;
    b.aux = a.1;
    // print("We are forging here also.");
}

forge (a: [u64]) as (b: two_tup) {
    b.val = a[0];
    b.aux = a[1];
    // print("We are forging here again.");
}

fn main(): i32 {
    // print("This is main.");
    let b: [u64] = fib(30);
    // // print(b);

    let a: two_tup = [1, 2] as (two_tup);
    // // print(a);
    let tup: (u64, u64) = a as ((u64, u64));
    // // print(tup);

}