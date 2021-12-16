use std::fs;
use std::str::Split;

fn print_type_of<T>(_: &T) {
    println!("{}", std::any::type_name::<T>())
}

fn read_vals() -> Vec<u32> {
    let data = fs::read_to_string("input3").expect("error reading file");

    data.split("\n").map(|x| {
        isize::from_str_radix(x, 2).unwrap() as u32
    }).collect()
}

fn next_power_of_2(n: u32) -> u32 {
    let mut n = n;
    n-=1;

    let mut p2 = 1;
    while n!=0 {
        n=n>>1;
        p2=p2<<1;
    }

    

    return p2;
}

fn p3() {
    let mut bits_count = [0; 12];
    let diagnosises = read_vals();
    for entry in &diagnosises {
        for i in 0..12 {
            let prev = bits_count[i];
            bits_count[i]+=(entry<<(20+i))>>31;
            assert!(bits_count[i]-prev<=1);
        }
    }
    
    let cutoff = (diagnosises.len()/2) as u32;
    let mut gamma: u32 = 0;

    for bit_c in bits_count {
        let bit = if bit_c >= cutoff { 1 } else { 0 };
        gamma = 2*gamma + bit;
    }

    let mut epsilon = next_power_of_2(gamma);
    epsilon = epsilon -1 - gamma;
    
    print!("{}\n", gamma*epsilon);
}

fn main() {
    p3();
}
