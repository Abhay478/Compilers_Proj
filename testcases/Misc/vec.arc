fn main(): i32 {
    let a: Vec<i32> = [1, 2, 3] as (Vec<i32>);
    let c: Vec<i32> = a + a; 
    let e: i32 = a @ a;
    print(c as (str));
    let b: Vec<i32> = 3 * a;
    print(b as (str));
    let d: i32 = a[0];
}
