# Create a virtual environment with all tools installed
# ref: https://hub.docker.com/_/alpine
FROM alpine:edge AS env
LABEL maintainer="mizux.dev@gmail.com"
# Install system dependencies
ENV PATH=$PATH:/usr/local/bin
apk add --no-cache \
 g++ clang make cmake \
 doxygen graphviz \
 qt5-qtbase-dev

CMD [ "bash" ]


# Add the app src to our build env
FROM env AS devel
# Create app directory
WORKDIR /home/app
# Bundle app source
COPY . .

CMD [ "bash" ]


# Create a production image
FROM alpine:edge AS prod
LABEL maintainer="mizux.dev@gmail.com"
# Install system dependencies
ENV PATH=$PATH:/usr/local/bin
apk add --no-cache qt5-qtbase

# Create app directory
WORKDIR /home/app
# Copy app from devel to prod
COPY --from=devel /home/app/install /home/app

CMD [ "bash" ]
