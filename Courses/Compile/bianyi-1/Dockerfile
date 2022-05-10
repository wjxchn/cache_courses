FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN gcc wjx-program.c -o wjx-program
RUN chmod +x wjx-program