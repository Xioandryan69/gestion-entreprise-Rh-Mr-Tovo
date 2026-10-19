cd build;
rm -rf *;

if cmake ..; then
    if make; then
        sleep 2
        clear
        ./exec
    else
        echo "Erreur lors du MAKE"
    fi
else
    echo "Erreur lors du CMAKE"
fi