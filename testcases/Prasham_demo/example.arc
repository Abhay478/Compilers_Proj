struct two_tup {
    val: u64,
    aux: u64
}

claim two_tup is Group {
    (c = 0) => {
        c.val = 0;
        c.aux = 0;
    }

    (c = a + b) => {
        c.val = a.val + b.val;
        c.aux = a.aux + b.aux;
        return;
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

    let a: two_tup = [1, 2] as (two_tup); // third forge

    let tup: (u64, u64) = a as ((u64, u64)); // first forge

    let twoTup: two_tup = tup as (two_tup); // second forge
    print(twoTup.val as (str));
    print(twoTup.aux as (str));

    let b: two_tup = [3, 4] as (two_tup); // third forge
   
    let c: two_tup = a + b; // Group implementation
    print(c.val as (str));
    print(c.aux as (str));


}
