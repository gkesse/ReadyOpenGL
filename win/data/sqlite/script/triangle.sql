DROP TABLE IF EXISTS triangle;

CREATE TABLE triangle (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    --
    point_1_x REAL,
    point_1_y REAL,
    point_1_z REAL,
    --
    point_2_x REAL,
    point_2_y REAL,
    point_2_z REAL,
    --
    point_3_x REAL,
    point_3_y REAL,
    point_3_z REAL,
    --
    color_1_r REAL,
    color_1_g REAL,
    color_1_b REAL,
    color_1_a REAL,
    --
    color_2_r REAL,
    color_2_g REAL,
    color_2_b REAL,
    color_2_a REAL,
    --
    color_3_r REAL,
    color_3_g REAL,
    color_3_b REAL,
    color_3_a REAL
);

INSERT INTO triangle (point_1_x, point_1_y, point_1_z, point_2_x, point_2_y, point_2_z, point_3_x, point_3_y, point_3_z,  color_1_r, color_1_g, color_1_b, color_1_a, color_2_r, color_2_g, color_2_b, color_2_a, color_3_r, color_3_g, color_3_b, color_3_a) VALUES
(-0.6, -0.4, 0.0, 0.6, -0.4, 0.0, 0.0, 0.6, 0.0, 0.5, 0.0, 0.0, 1.0, 0.5, 0.0, 0.0, 1.0, 0.5, 0.0, 0.0, 1.0);
INSERT INTO triangle (point_1_x, point_1_y, point_1_z, point_2_x, point_2_y, point_2_z, point_3_x, point_3_y, point_3_z,  color_1_r, color_1_g, color_1_b, color_1_a, color_2_r, color_2_g, color_2_b, color_2_a, color_3_r, color_3_g, color_3_b, color_3_a) VALUES
(-0.6, -0.4, 0.0, 0.6, -0.4, 0.0, 0.0, 0.6, 0.0, 0.5, 0.0, 0.0, 1.0, 0.5, 0.0, 0.0, 1.0, 0.5, 0.0, 0.0, 1.0);
INSERT INTO triangle (point_1_x, point_1_y, point_1_z, point_2_x, point_2_y, point_2_z, point_3_x, point_3_y, point_3_z,  color_1_r, color_1_g, color_1_b, color_1_a, color_2_r, color_2_g, color_2_b, color_2_a, color_3_r, color_3_g, color_3_b, color_3_a) VALUES
(-0.6, -0.4, 0.0, 0.6, -0.4, 0.0, 0.0, 0.6, 0.0, 0.5, 0.0, 0.0, 1.0, 0.5, 0.0, 0.0, 1.0, 0.5, 0.0, 0.0, 1.0);
