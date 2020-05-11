while true
    time=$(date "+[%Y/%m/%d-%H:%M:%S]")
    do
        echo "${time}"
        free
        sleep 1
    done