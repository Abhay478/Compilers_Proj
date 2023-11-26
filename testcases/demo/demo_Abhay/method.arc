
struct Bar{
    x: i32
}

fn Bar.foo1(): i32 {
    print("Hello from foo1.");
    return 0;
}
fn Bar.foo2(): u64 {
    print("Hello from foo2.");
    return 0;
}

fn main(): i32 {
    let u: Bar;
    print(".");
    u.foo1();
    u.foo2();
}