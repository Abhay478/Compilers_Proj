enum Status {
    Active,
    Inactive,
    Unknown
}

struct Employee {
    id: u32,
    name: str,
    status: Status
}

fn updateStatus(emp: Employee, newStatus: Status): Employee {
    emp.status = newStatus;
    return emp;
}

fn fibonacci(n: u32): [u32] {
    let fib: [u32] = [0, 1];
    for (let i: u32 = 2; i < n; i++) {
        let next: u32 = fib[i - 1] + fib[i - 2];
        fib.push(next);
    }
    return fib;
}

fn main(): i32 {
    let e: Employee = {id: 123, name: "Sumedh", status: Status::Active};
    let updatedEmployee: Employee = updateStatus(e, Status::Inactive);

    let fibSeries: [u32] = fibonacci(10);
    for num in fibSeries {

        print(num as (str));
        print(", ");
    }

    return 0;
}
