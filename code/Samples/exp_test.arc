struct Foo {
    x: u32
}

forge (a: Foo) as (b: u32) {
    b = a.x;
}

fn main() {
    let q: Foo;
    q.x = 10;
    let a: u32 = q as (u32);
    let b: [u32] = [1, 2, 3];
    if(a in b) {
        print("eh");
    }
    else {
        print("pfft");
    }
}