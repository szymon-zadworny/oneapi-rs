fn main() {
    let compiler_root = std::env::var("CMPLR_ROOT")
        .expect("No valid OneAPI installation found.");

    cxx_build::bridge("src/main.rs")
        .compiler(compiler_root + "/bin/icpx")
        .flag("-fsycl")
        .file("src/shim.cpp")
        .std("c++17")
        .compile("test");

    println!("cargo:rerun-if-changed=src/test.cpp");
    println!("cargo:rerun-if-changed=include/shim.hpp");
}