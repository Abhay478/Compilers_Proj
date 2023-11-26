struct two_tup {
    val: u64,
    aux: u64
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

forge (a: two_tup) as (b: [u64]) {
    push(b, a.val);
    push(b, a.aux);
}

fn main(): i32 {
    // print("This is main.");

    let a: two_tup = [1, 2] as (two_tup); // third forge
    let b: two_tup = [3, 4] as (two_tup); // third forge


    let tup: (u64, u64) = a as ((u64, u64)); // first forge
    print(tup.0 as (str));
    print(tup.1 as (str));

    let twoTup: two_tup = tup as (two_tup); // second forge
    print(twoTup.val as (str));
    print(twoTup.aux as (str));

    let arr: [u64] = b as ([u64]);
    print(arr[0] as (str));
    print(arr[1] as (str));
}
