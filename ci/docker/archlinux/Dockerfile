# Create a virtual environment with all tools installed
# ref: https://hub.docker.com/_/archlinux/
FROM archlinux:latest AS env

# Install system build dependencies
ENV PATH=/usr/local/bin:$PATH
RUN pacman -Syu --noconfirm \
git base-devel cmake \
qt6 ttf-dejavu

FROM env AS devel
WORKDIR /home/app
COPY . .

FROM devel AS build
RUN cmake --version
RUN cmake -S. -Bbuild
RUN cmake --build build --target all -v
RUN cmake --build build --target install -v

FROM build AS test
RUN cmake --build build --target test

# Create a production image
FROM archlinux:latest AS prod

RUN pacman -Syu --noconfirm qt6 ttf-dejavu
# Create app directory
WORKDIR /home/app
COPY --from=build /usr/local/ .
