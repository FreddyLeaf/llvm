// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32i -x c -E -dM %s \
// RUN: -o - | FileCheck %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64i -x c -E -dM %s \
// RUN: -o - | FileCheck %s

// CHECK-NOT: __riscv_div {{.*$}}
// CHECK-NOT: __riscv_m {{.*$}}
// CHECK-NOT: __riscv_mul {{.*$}}
// CHECK-NOT: __riscv_muldiv {{.*$}}
// CHECK-NOT: __riscv_a {{.*$}}
// CHECK-NOT: __riscv_atomic
// CHECK-NOT: __riscv_f {{.*$}}
// CHECK-NOT: __riscv_d {{.*$}}
// CHECK-NOT: __riscv_flen {{.*$}}
// CHECK-NOT: __riscv_fdiv {{.*$}}
// CHECK-NOT: __riscv_fsqrt {{.*$}}
// CHECK-NOT: __riscv_c {{.*$}}
// CHECK-NOT: __riscv_compressed {{.*$}}
// CHECK-NOT: __riscv_b {{.*$}}
// CHECK-NOT: __riscv_bitmanip {{.*$}}
// CHECK-NOT: __riscv_zihintntl {{.*$}}
// CHECK-NOT: __riscv_zba {{.*$}}
// CHECK-NOT: __riscv_zbb {{.*$}}
// CHECK-NOT: __riscv_zbc {{.*$}}
// CHECK-NOT: __riscv_zbs {{.*$}}
// CHECK-NOT: __riscv_zfh {{.*$}}
// CHECK-NOT: __riscv_v {{.*$}}
// CHECK-NOT: __riscv_vector {{.*$}}
// CHECK-NOT: __riscv_v_intrinsic {{.*$}}
// CHECK-NOT: __riscv_zbkc {{.*$}}
// CHECK-NOT: __riscv_zbkx {{.*$}}
// CHECK-NOT: __riscv_zbkb {{.*$}}
// CHECK-NOT: __riscv_zkne {{.*$}}
// CHECK-NOT: __riscv_zknd {{.*$}}
// CHECK-NOT: __riscv_zknh {{.*$}}
// CHECK-NOT: __riscv_zksh {{.*$}}
// CHECK-NOT: __riscv_zksed {{.*$}}
// CHECK-NOT: __riscv_zkr {{.*$}}
// CHECK-NOT: __riscv_zkt {{.*$}}
// CHECK-NOT: __riscv_zk {{.*$}}
// CHECK-NOT: __riscv_zicbom {{.*$}}
// CHECK-NOT: __riscv_zicboz {{.*$}}
// CHECK-NOT: __riscv_svnapot {{.*$}}
// CHECK-NOT: __riscv_svpbmt {{.*$}}
// CHECK-NOT: __riscv_svinval {{.*$}}
// CHECK-NOT: __riscv_xventanacondops {{.*$}}
// CHECK-NOT: __riscv_zca {{.*$}}
// CHECK-NOT: __riscv_zcb {{.*$}}
// CHECK-NOT: __riscv_zcd {{.*$}}
// CHECK-NOT: __riscv_zcf {{.*$}}
// CHECK-NOT: __riscv_h {{.*$}}

// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32i -x c -E -dM %s \
// RUN: -o - | FileCheck %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64i -x c -E -dM %s \
// RUN: -o - | FileCheck %s
// CHECK: __riscv_i 2000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32im -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-M-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64im -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-M-EXT %s
// CHECK-M-EXT: __riscv_div 1
// CHECK-M-EXT: __riscv_m 2000000{{$}}
// CHECK-M-EXT: __riscv_mul 1
// CHECK-M-EXT: __riscv_muldiv 1

// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32ia -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-A-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64ia -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-A-EXT %s
// CHECK-A-EXT: __riscv_a 2000000{{$}}
// CHECK-A-EXT: __riscv_atomic 1

// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32if -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-F-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64if -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-F-EXT %s
// CHECK-F-EXT: __riscv_f 2000000{{$}}
// CHECK-F-EXT: __riscv_fdiv 1
// CHECK-F-EXT: __riscv_flen 32
// CHECK-F-EXT: __riscv_fsqrt 1

// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32ifd -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-D-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64ifd -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-D-EXT %s
// CHECK-D-EXT: __riscv_d 2000000{{$}}
// CHECK-D-EXT: __riscv_fdiv 1
// CHECK-D-EXT: __riscv_flen 64
// CHECK-D-EXT: __riscv_fsqrt 1

// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32ifd -mabi=ilp32 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-SOFT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64ifd -mabi=lp64 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-SOFT %s
// CHECK-SOFT: __riscv_float_abi_soft 1
// CHECK-SOFT-NOT: __riscv_float_abi_single
// CHECK-SOFT-NOT: __riscv_float_abi_double

// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32ifd -mabi=ilp32f -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-SINGLE %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64ifd -mabi=lp64f -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-SINGLE %s
// CHECK-SINGLE: __riscv_float_abi_single 1
// CHECK-SINGLE-NOT: __riscv_float_abi_soft
// CHECK-SINGLE-NOT: __riscv_float_abi_double

// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32ifd -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-DOUBLE %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64ifd -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-DOUBLE %s
// CHECK-DOUBLE: __riscv_float_abi_double 1
// CHECK-DOUBLE-NOT: __riscv_float_abi_soft
// CHECK-DOUBLE-NOT: __riscv_float_abi_single

// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32ic -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-C-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64ic -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-C-EXT %s
// CHECK-C-EXT: __riscv_c 2000000{{$}}
// CHECK-C-EXT: __riscv_compressed 1

// RUN: %clang -target riscv32-unknown-linux-gnu -menable-experimental-extensions \
// RUN: -march=rv32izihintntl0p2 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZIHINTNTL-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -menable-experimental-extensions \
// RUN: -march=rv64izihintntl0p2 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZIHINTNTL-EXT %s
// CHECK-ZIHINTNTL-EXT: __riscv_zihintntl 2000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32izba1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBA-EXT %s
// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32izba -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBA-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izba1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBA-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izba -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBA-EXT %s
// CHECK-ZBA-NOT: __riscv_b
// CHECK-ZBA-EXT: __riscv_zba 1000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32izbb1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBB-EXT %s
// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32izbb -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBB-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izbb1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBB-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izbb -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBB-EXT %s
// CHECK-ZBB-NOT: __riscv_b
// CHECK-ZBB-EXT: __riscv_zbb 1000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32izbc1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBC-EXT %s
// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32izbc -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBC-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izbc1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBC-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izbc -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBC-EXT %s
// CHECK-ZBC-NOT: __riscv_b
// CHECK-ZBC-EXT: __riscv_zbc 1000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32izbs1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBS-EXT %s
// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32izbs -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBS-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izbs1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBS-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izbs -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZBS-EXT %s
// CHECK-ZBS-NOT: __riscv_b
// CHECK-ZBS-EXT: __riscv_zbs 1000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32iv1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-V-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64iv1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-V-EXT %s
// CHECK-V-EXT: __riscv_v 1000000{{$}}
// CHECK-V-EXT: __riscv_vector 1

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32izfhmin1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZFHMIN-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izfhmin1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZFHMIN-EXT %s
// CHECK-ZFHMIN-EXT: __riscv_f 2000000{{$}}
// CHECK-ZFHMIN-EXT: __riscv_zfhmin 1000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32izfh1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZFH-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izfh1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZFH-EXT %s
// CHECK-ZFH-EXT: __riscv_f 2000000{{$}}
// CHECK-ZFH-EXT: __riscv_zfh 1000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv64iv1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-V-MINVLEN %s
// CHECK-V-MINVLEN: __riscv_v_elen 64
// CHECK-V-MINVLEN: __riscv_v_elen_fp 64
// CHECK-V-MINVLEN: __riscv_v_min_vlen 128

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv64iv1p0_zvl256b1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVL256b %s
// CHECK-ZVL256b: __riscv_v_min_vlen 256

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv64iv1p0_zvl512b1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVL512b %s
// CHECK-ZVL512b: __riscv_v_min_vlen 512

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv64iv1p0_zvl1024b1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVL1024b %s
// CHECK-ZVL1024b: __riscv_v_min_vlen 1024

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv64iv1p0_zvl2048b1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVL2048b %s
// CHECK-ZVL2048b: __riscv_v_min_vlen 2048

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv64iv1p0_zvl4096b1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVL4096b %s
// CHECK-ZVL4096b: __riscv_v_min_vlen 4096

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv64iv1p0_zvl8192b1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVL8192b %s
// CHECK-ZVL8192b: __riscv_v_min_vlen 8192

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv64iv1p0_zvl16384b1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVL16384b %s
// CHECK-ZVL16384b: __riscv_v_min_vlen 16384

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv64iv1p0_zvl32768b1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVL32768b %s
// CHECK-ZVL32768b: __riscv_v_min_vlen 32768

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv64iv1p0_zvl65536b1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVL65536b %s
// CHECK-ZVL65536b: __riscv_v_min_vlen 65536

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64ifdzve64d1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVE64D-EXT %s
// CHECK-ZVE64D-EXT: __riscv_v_elen 64
// CHECK-ZVE64D-EXT: __riscv_v_elen_fp 64
// CHECK-ZVE64D-EXT: __riscv_v_intrinsic 11000{{$}}
// CHECK-ZVE64D-EXT: __riscv_v_min_vlen 64
// CHECK-ZVE64D-EXT: __riscv_vector 1
// CHECK-ZVE64D-EXT: __riscv_zve32f 1000000{{$}}
// CHECK-ZVE64D-EXT: __riscv_zve32x 1000000{{$}}
// CHECK-ZVE64D-EXT: __riscv_zve64d 1000000{{$}}
// CHECK-ZVE64D-EXT: __riscv_zve64f 1000000{{$}}
// CHECK-ZVE64D-EXT: __riscv_zve64x 1000000{{$}}

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64ifzve64f1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVE64F-EXT %s
// CHECK-ZVE64F-EXT: __riscv_v_elen 64
// CHECK-ZVE64F-EXT: __riscv_v_elen_fp 32
// CHECK-ZVE64F-EXT: __riscv_v_intrinsic 11000{{$}}
// CHECK-ZVE64F-EXT: __riscv_v_min_vlen 64
// CHECK-ZVE64F-EXT: __riscv_vector 1
// CHECK-ZVE64F-EXT: __riscv_zve32f 1000000{{$}}
// CHECK-ZVE64F-EXT: __riscv_zve32x 1000000{{$}}
// CHECK-ZVE64F-EXT: __riscv_zve64f 1000000{{$}}
// CHECK-ZVE64F-EXT: __riscv_zve64x 1000000{{$}}

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izve64x1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVE64X-EXT %s
// CHECK-ZVE64X-EXT: __riscv_v_elen 64
// CHECK-ZVE64X-EXT: __riscv_v_elen_fp 0
// CHECK-ZVE64X-EXT: __riscv_v_intrinsic 11000{{$}}
// CHECK-ZVE64X-EXT: __riscv_v_min_vlen 64
// CHECK-ZVE64X-EXT: __riscv_vector 1
// CHECK-ZVE64X-EXT: __riscv_zve32x 1000000{{$}}
// CHECK-ZVE64X-EXT: __riscv_zve64x 1000000{{$}}

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64ifzve32f1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVE32F-EXT %s
// CHECK-ZVE32F-EXT: __riscv_v_elen 32
// CHECK-ZVE32F-EXT: __riscv_v_elen_fp 32
// CHECK-ZVE32F-EXT: __riscv_v_intrinsic 11000{{$}}
// CHECK-ZVE32F-EXT: __riscv_v_min_vlen 32
// CHECK-ZVE32F-EXT: __riscv_vector 1
// CHECK-ZVE32F-EXT: __riscv_zve32f 1000000{{$}}
// CHECK-ZVE32F-EXT: __riscv_zve32x 1000000{{$}}

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izve32x1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZVE32X-EXT %s
// CHECK-ZVE32X-EXT: __riscv_v_elen 32
// CHECK-ZVE32X-EXT: __riscv_v_elen_fp 0
// CHECK-ZVE32X-EXT: __riscv_v_intrinsic 11000{{$}}
// CHECK-ZVE32X-EXT: __riscv_v_min_vlen 32
// CHECK-ZVE32X-EXT: __riscv_vector 1
// CHECK-ZVE32X-EXT: __riscv_zve32x 1000000{{$}}

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izbkc1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZBKC-EXT %s
// CHECK-ZBKC-EXT: __riscv_zbkc

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izbkx1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZBKX-EXT %s
// CHECK-ZBKX-EXT: __riscv_zbkx

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izbkb1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZBKB-EXT %s
// CHECK-ZBKB-EXT: __riscv_zbkb

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izknd1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZKND-EXT %s
// CHECK-ZKND-EXT: __riscv_zknd

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izkne1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZKNE-EXT %s
// CHECK-ZKNE-EXT: __riscv_zkne

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izknh1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZKNH-EXT %s
// CHECK-ZKNH-EXT: __riscv_zknh

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izksh1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZKSH-EXT %s
// CHECK-ZKSH-EXT: __riscv_zksh

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izksed1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZKSED-EXT %s
// CHECK-ZKSED-EXT: __riscv_zksed

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izkr1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZKR-EXT %s
// CHECK-ZKR-EXT: __riscv_zkr

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izkt1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZKT-EXT %s
// CHECK-ZKT-EXT: __riscv_zkt

// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64izk1p0 -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-ZK-EXT %s
// CHECK-ZK-EXT: __riscv_zk

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32i_zkn_zkt_zkr -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-COMBINE-INTO-ZK %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64i_zkn_zkt_zkr -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-COMBINE-INTO-ZK %s
// CHECK-COMBINE-INTO-ZK: __riscv_zk 1

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32i_zbkb_zbkc_zbkx_zkne_zknd_zknh -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-COMBINE-INTO-ZKN %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64i_zbkb_zbkc_zbkx_zkne_zknd_zknh -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-COMBINE-INTO-ZKN %s
// CHECK-COMBINE-INTO-ZKN: __riscv_zkn 1

// RUN: %clang -target riscv32-unknown-linux-gnu \
// RUN: -march=rv32i_zbkb_zbkc_zbkx_zksed_zksh -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-COMBINE-INTO-ZKS %s
// RUN: %clang -target riscv64-unknown-linux-gnu \
// RUN: -march=rv64i_zbkb_zbkc_zbkx_zksed_zksh -x c -E -dM %s -o - \
// RUN: | FileCheck --check-prefix=CHECK-COMBINE-INTO-ZKS %s
// CHECK-COMBINE-INTO-ZKS: __riscv_zks 1

// RUN: %clang -target riscv32 -march=rv32izicbom -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZICBOM-EXT %s
// RUN: %clang -target riscv64 -march=rv64izicbom -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZICBOM-EXT %s
// CHECK-ZICBOM-EXT: __riscv_zicbom 1000000{{$}}

// RUN: %clang -target riscv32 -march=rv32izicboz -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZICBOZ-EXT %s
// RUN: %clang -target riscv64 -march=rv64izicboz -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZICBOZ-EXT %s
// CHECK-ZICBOZ-EXT: __riscv_zicboz 1000000{{$}}

// RUN: %clang -target riscv32 -march=rv32izicbop -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZICBOP-EXT %s
// RUN: %clang -target riscv64 -march=rv64izicbop -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZICBOP-EXT %s
// CHECK-ZICBOP-EXT: __riscv_zicbop 1000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu -menable-experimental-extensions \
// RUN: -march=rv32izawrs1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZAWRS-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -menable-experimental-extensions \
// RUN: -march=rv64izawrs1p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZAWRS-EXT %s
// CHECK-ZAWRS-EXT: __riscv_zawrs 1000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu -menable-experimental-extensions \
// RUN: -march=rv32iztso0p1 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZTSO-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -menable-experimental-extensions \
// RUN: -march=rv64iztso0p1 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZTSO-EXT %s
// CHECK-ZTSO-EXT: __riscv_ztso 1000{{$}}

// RUN: %clang -target riscv32 -march=rv32isvnapot -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-SVNAPOT-EXT %s
// RUN: %clang -target riscv64 -march=rv64isvnapot -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-SVNAPOT-EXT %s
// CHECK-SVNAPOT-EXT: __riscv_svnapot 1000000{{$}}

// RUN: %clang -target riscv32 -march=rv32isvpbmt -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-SVPBMT-EXT %s
// RUN: %clang -target riscv64 -march=rv64isvpbmt -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-SVPBMT-EXT %s
// CHECK-SVPBMT-EXT: __riscv_svpbmt 1000000{{$}}

// RUN: %clang -target riscv32 -march=rv32isvinval -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-SVINVAL-EXT %s
// RUN: %clang -target riscv64 -march=rv64isvinval -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-SVINVAL-EXT %s
// CHECK-SVINVAL-EXT: __riscv_svinval 1000000{{$}}

// RUN: %clang -target riscv32 -march=rv32ih -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-H-EXT %s
// RUN: %clang -target riscv64 -march=rv64ih -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-H-EXT %s
// CHECK-H-EXT: __riscv_h 1000000{{$}}

// RUN: %clang -target riscv64 -march=rv64ixventanacondops -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-XVENTANACONDOPS-EXT %s
// CHECK-XVENTANACONDOPS-EXT: __riscv_xventanacondops 1000000{{$}}

// RUN: %clang -target riscv64 -march=rv64ixtheadvdot -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-XTHEADVDOT-EXT %s
// CHECK-XTHEADVDOT-EXT: __riscv_xtheadvdot 1000000{{$}}

// RUN: %clang -target riscv32 -march=rv32izca1p0 -menable-experimental-extensions \
// RUN: -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-ZCA-EXT %s
// RUN: %clang -target riscv64 -march=rv64izca1p0 -menable-experimental-extensions \
// RUN: -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-ZCA-EXT %s
// CHECK-ZCA-EXT: __riscv_zca 1000000{{$}}

// RUN: %clang -target riscv32 -march=rv32izcb1p0 -menable-experimental-extensions \
// RUN: -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-ZCB-EXT %s
// RUN: %clang -target riscv64 -march=rv64izcb1p0 -menable-experimental-extensions \
// RUN: -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-ZCB-EXT %s
// CHECK-ZCB-EXT: __riscv_zca 1000000{{$}}
// CHECK-ZCB-EXT: __riscv_zcb 1000000{{$}}

// RUN: %clang -target riscv32 -march=rv32izcd1p0 -menable-experimental-extensions \
// RUN: -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-ZCD-EXT %s
// RUN: %clang -target riscv64 -march=rv64izcd1p0 -menable-experimental-extensions \
// RUN: -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-ZCD-EXT %s
// CHECK-ZCD-EXT: __riscv_zcd 1000000{{$}}

// RUN: %clang -target riscv32 -march=rv32izcf1p0 -menable-experimental-extensions \
// RUN: -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-ZCF-EXT %s
// CHECK-ZCF-EXT: __riscv_zcf 1000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32izicsr2p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZICSR-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64izicsr2p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZICSR-EXT %s
// CHECK-ZICSR-EXT: __riscv_zicsr 2000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu -march=rv32izifencei2p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZIFENCEI-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -march=rv64izifencei2p0 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZIFENCEI-EXT %s
// CHECK-ZIFENCEI-EXT: __riscv_zifencei 2000000{{$}}

// RUN: %clang -target riscv32-unknown-linux-gnu -menable-experimental-extensions \
// RUN: -march=rv32izfa0p1 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZFA-EXT %s
// RUN: %clang -target riscv64-unknown-linux-gnu -menable-experimental-extensions \
// RUN: -march=rv64izfa0p1 -x c -E -dM %s \
// RUN: -o - | FileCheck --check-prefix=CHECK-ZFA-EXT %s
// CHECK-ZFA-EXT: __riscv_zfa 1000{{$}}
