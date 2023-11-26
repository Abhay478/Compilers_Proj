fn main: i32 {
    let a: Vec<u64> = [1, 2, 3] as (Vec<u64>);
    let b: Vec<u64> = a * 2;
    let c = a + b; 
    let d: u64 = a[0];
}