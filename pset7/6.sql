SELECT avg(rating) FROM ratings WHERE movie_id in (SELECT DISTINCT id FROM movies WHERE year = '2012');
