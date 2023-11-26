fn main(): i32 {
    let x: str = "asdfasdf";
    let y: &str = &x;
    *y = "qwerqwer";
    print(x);
}
