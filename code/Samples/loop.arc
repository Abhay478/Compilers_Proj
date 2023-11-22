fn foo(): u32 {
    return 2;
}

fn main() {
    let a: u32;
    let b: u32 = foo();
    for(a = 3; a < 5; a++) {
        b++;
    }
}