struct Vector2D {
    x: float,
    y: float
}

claim Vector2D is Space {
    (result = a * k) => {
        result.x = a.x * k;
        result.y = a.y * k;
    }
}

forge (arr: [float]) as (vec: Vector2D) {
    vec.x = arr[0];
    vec.y = arr[1];
}

fn vectorMagnitude(vec: Vector2D): float {
    return (vec.x * vec.x + vec.y * vec.y).sqrt();
}

fn main(): i32 {
    let v1: Vector2D = [3.0, 4.0] as (Vector2D);
    let v2: Vector2D = v1 * 2.0; // Scaling the vector

    let mag: float = vectorMagnitude(v2);
    print("Magnitude of v2: ");
    print(mag);

    if (mag > 10.0) {
        print("Large vector");
    } else {
        print("Small vector");
    }

    return 0;
}
