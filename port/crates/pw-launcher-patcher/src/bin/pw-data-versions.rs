use std::env;
use std::process;
use pw_core::resolve_data_dir;
use pw_launcher_patcher::inspect_pw_data_versions;

fn main() {
    let arg = env::args().nth(1);
    let dir = match resolve_data_dir(arg.as_deref()) {
        Ok(p) => p,
        Err(e) => {
            eprintln!("Error: {e}");
            process::exit(1);
        }
    };
    let rows = match inspect_pw_data_versions(&dir) {
        Ok(r) => r,
        Err(e) => {
            eprintln!("PW_Data_Versions failed on '{}': {e}", dir.display());
            process::exit(1);
        }
    };
    println!("{}", dir.display());
    for r in rows {
        println!("{}", r.to_save_line());
    }
}
