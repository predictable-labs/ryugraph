def test_version() -> None:
    import ryu

    assert kuzu.version != ""
    assert kuzu.storage_version > 0
    assert kuzu.version == kuzu.__version__
