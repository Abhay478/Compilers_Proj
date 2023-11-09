fn foo(): u32 {
  return "hello";
}

fn main() {
  let a: u32 = foo();
  let b: u32 = foo(a);
}
