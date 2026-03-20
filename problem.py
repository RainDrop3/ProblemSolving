from __future__ import annotations

import argparse
from pathlib import Path


def create_problem(path_arg: str) -> None:
    base_dir = Path.cwd()
    target_dir = base_dir / Path(path_arg)
    target_dir.mkdir(parents=True, exist_ok=True)

    leaf_name = target_dir.name
    cpp_path = target_dir / f"{leaf_name}.cpp"
    if not cpp_path.exists():
        cpp_path.write_text("", encoding="utf-8")
        print(f"[created] {cpp_path}")
    else:
        print(f"[exists ] {cpp_path}")

    template_path = Path(__file__).resolve().parent / "Retrospective Template.md"
    retrospective_path = target_dir / "Retrospective.md"

    if not template_path.exists():
        raise FileNotFoundError(f"Template not found: {template_path}")

    if not retrospective_path.exists():
        retrospective_path.write_text(template_path.read_text(encoding="utf-8"), encoding="utf-8")
        print(f"[created] {retrospective_path}")
    else:
        print(f"[exists ] {retrospective_path}")


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Create a problem directory with <leaf>.cpp and Retrospective.md",
    )
    parser.add_argument(
        "path",
        help="Target path like BOJ/1192",
    )
    args = parser.parse_args()

    create_problem(args.path)


if __name__ == "__main__":
    main()
