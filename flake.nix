{
  description = "Lightweight XDOJ C/C++ solution workspace";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs =
    { nixpkgs, ... }:
    let
      systems = [
        "x86_64-linux"
        "aarch64-linux"
      ];

      forAllSystems = nixpkgs.lib.genAttrs systems;

      pkgsFor = forAllSystems (
        system:
        import nixpkgs {
          inherit system;
        }
      );
    in
    {
      formatter = forAllSystems (system: pkgsFor.${system}.nixfmt-tree);

      devShells = forAllSystems (
        system:
        let
          pkgs = pkgsFor.${system};
        in
        {
          default = pkgs.mkShell {
            packages = [
              pkgs.bash
              pkgs.coreutils
              pkgs.diffutils
              pkgs.findutils
              pkgs.gawk
              pkgs.gcc
              pkgs.gdb
              pkgs.gnugrep
              pkgs.gnumake
              pkgs.gnused
              pkgs.just
              pkgs.clang-tools
              pkgs.time
              pkgs.zsh
            ]
            ++ pkgs.lib.optionals pkgs.stdenv.isLinux [
              pkgs.valgrind
            ];

            shellHook = ''
              export CC=''${CC:-gcc}
              export CXX=''${CXX:-g++}
              export OJ_STD=''${OJ_STD:-gnu++17}
              export OJ_CSTD=''${OJ_CSTD:-gnu17}

              echo "XDOJ dev shell ready."
              echo "Run 'just --list' to see available commands."
            '';
          };
        }
      );
    };
}
