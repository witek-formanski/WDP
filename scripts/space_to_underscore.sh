for f in /pdf/*\ *; do
  if [ -f "$f" ]; then
    mv "$f" "${f// /_}"
  fi
done