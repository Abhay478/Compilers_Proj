
fn fib(n: u32) : Buf<u32> {
    let a: BigInt = 0;
    let b: BigInt = 1;
    let out: Buf<BigInt> = [a, b];
    for (i: u32 = 2; i < n; i++) {
        let c: u32 = a + b;
        a = b;
        b = c;
        out.push(c);
    }

    return out;
}

struct two_tup {
    val: BigInt,
    aux: BigInt,
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
        c.val = -a.val;
        c.aux = -a.aux
    }
}

forge (a: two_tup) as (b: (BigInt, BigInt)) {
    b = (a.val, a.aux);
    print("We are forging here.");
}

forge (a: (BigInt, BigInt)) as (b: two_tup) {
    b.val = a.0;
    b.aux = a.1;
    print("We are forging here also.");
}

forge (a: Buf<BigInt>) as (b: two_tup) {
    b.val = a[0];
    b.aux = a[1];
    print("We are forging here again.");
}

fn main() {
    print("This is main.");
    let b: Buf<BigInt> = fib(30);
    print(b);

    let a: two_tup = [1, 2] as two_tup;
    print(a);
    let tup: (BigInt, BigInt) = a as (BigInt, BigInt);
    print(tup);

    
}