    while (i <= n)
    {
        int current = i;
        i++; // 更新放在 continue 之前，保证一定执行
        if (current % 2 == 0)
        {
            continue;
        }
        sum += current;
    }
