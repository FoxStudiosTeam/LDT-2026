```python -m venv venv```

```.\venv\Scripts\activate```

```pip install -r req```

``` ROS_DOMAIN_ID=42 py main.py ../doubleT_platform/ --loop --topics /lidar_points```

or

```docker build -t bag-player .```

```docker run --rm -it --network host -e ROS_DOMAIN_ID=42 -v "../dataset:/app/dataset" bag-player```
