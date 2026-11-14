from pathlib import Path


BRINGUP_DIR = Path(__file__).resolve().parents[1]


def test_m2_moveit_rviz_launch_combines_visual_scene_and_moveit_rviz():
    launch_path = BRINGUP_DIR / "launch" / "m2_moveit_rviz.launch.py"
    assert launch_path.exists()

    launch_text = launch_path.read_text(encoding="utf-8")

    for required in [
        "infrared_grasp_sim",
        "m2_visual_scene.launch.py",
        "infrared_grasp_moveit_config",
        "m2_moveit_rviz.launch.py",
    ]:
        assert required in launch_text
