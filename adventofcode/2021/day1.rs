use std::fs;
use std::str::Split;

fn print_type_of<T>(_: &T) {
    println!("{}", std::any::type_name::<T>())
}

fn read_vals() -> Vec<u32> {
    let data = fs::read_to_string("input1").expect("unable to read file");
//    print_type_of(&data);
    return data.split("\n")
        .map(|x| x.to_string().parse().unwrap())
        .collect();
//    print_type_of(&stuff);
//    print_type_of(&data.split("\n").collect());
//    return data.split("\n").collect();
}

fn p1() {
    let mut prev_val: u32 = 1_00_000_000;
    let mut count = 0;
    for sonar_val in read_vals() {
        if prev_val < sonar_val {
            count+=1;
        }
        prev_val = sonar_val;
    }

    print!("count is {}\n", count);
}

fn p2() {

    let mut count = 0;
    let sonar_values = read_vals();
    let mut prev_val: u32 = sonar_values[0]+sonar_values[1]+sonar_values[2];
    for i in 3..sonar_values.len() {
        let curr_val = prev_val + sonar_values[i]-sonar_values[i-3];
        if curr_val > prev_val {
            count+=1;
        }
    }

    print!("count is {}\n", count);
}


fn main() {
//    read_vals();
    p2();
}
