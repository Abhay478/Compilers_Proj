
struct Bar{
    x: i32
}

fn Bar.foo1(): i32 {
    print("Hello world.");
    return 0;
}
fn Bar.foo2(): u64 {
    print("Hello world.");
    return 0;
}

fn main(): i32 {
    let u: Bar;
    print(".");
    u.foo1();
}