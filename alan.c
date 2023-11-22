int main() {
    char *key = "key";
    char *text = "Another one bites the dust";

    int key_len = sizeof(key) / sizeof(key[0]);

    char *key_vec;

    for (int i = 0; i < key_len; i++) key_vec[i] = (unsigned int) key[i];

    char *result;

    for (int i = 0; i < text_len; i++) {
        result[i] = (char) (text[i] + key_vec[i % key_len] + 200);
    }

    printf(result);
}

/* Rust code
fn main() {
    let args = Args::parse();

    let key_vec: Vec<u32> = args.key.chars().map(|c| c as u32).collect();

    let result: String = args.text
        .chars()
        .enumerate()
        .map(|(i, v)| {
            char::from_u32(
                if args.decrypt { v as u32 + key_vec[i % key_vec.len()] - 200 }
                else            { v as u32 - key_vec[i % key_vec.len()] + 200 }
            ).unwrap()
        })
        .collect();

    println!("{result}");
}
*/