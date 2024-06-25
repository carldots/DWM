{
  description = "CarlDots' DWM build with LibXcursor support enabled";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-24.05";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { nixpkgs, utils, ... }@inputs:
    utils.lib.eachDefaultSystem (system: let
      pkgs = import nixpkgs {
        inherit system;

        overlays = [
          (final: prev: {
            dwm = prev.dwm.overrideAttrs (old: {
              src = ./.;
              buildInputs = with prev; old.buildInputs ++ [
                xorg.libXcursor
              ];
            });
          })
        ];
      };
    in {
      packages.default = pkgs.dwm;
    });
}
