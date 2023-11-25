fn main(): i32 {
    let x: [i32] = [1, 2, 0, 4, 3];
    let y: Symmetric<5> = x as (Symmetric<5>);
    let z: str = y as (str);
    print(z);
}
