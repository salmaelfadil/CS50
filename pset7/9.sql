SELECT DISTINCT name FROM people 
JOIN stars on stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id 
WHERE year = '2004' 
ORDER BY birth;
