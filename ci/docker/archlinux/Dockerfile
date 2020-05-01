# Create a virtual environment with all tools installed
# ref: https://hub.docker.com/_/archlinux/
FROM archlinux/base AS env
LABEL maintainer="mizux.dev@gmail.com"
# Install system build dependencies
ENV PATH=/usr/local/bin:$PATH
RUN pacman -Syu --noconfirm \
git base-devel cmake \
qt5 ttf-dejavu
CMD [ "/bin/sh" ]

FROM env AS devel
WORKDIR /home/app
COPY . .

FROM devel AS build
RUN cmake -version
RUN cmake -S. -Bbuild
RUN cmake --build build --target all -v
RUN cmake --build build --target install

FROM build AS test
RUN cmake --build build --target test

FROM env AS install_env
COPY --from=build /usr/local /usr/local/

# Create a production image
FROM archlinux/base AS prod
RUN pacman -Syu --noconfirm qt5 ttf-dejavu

# Create app directory
WORKDIR /home/app
COPY --from=build /home/app/build/install .

CMD [ "/bin/sh" ]
