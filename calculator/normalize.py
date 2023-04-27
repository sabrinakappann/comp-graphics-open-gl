def normalize(sruCoordinates: list, xwmin, xwmax, ywmin, ywmax) -> list:
    result = []
    for x, y in sruCoordinates:
        xNorm = (x - xwmin)/(xwmax - xwmin)
        yNorm = (y - ywmin)/(ywmax - ywmin)
        result.append([xNorm, yNorm])
    return result


if __name__ == "__main__":
    vertices = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']

    xwmin = -1
    xwmax = 5
    ywmin = -1
    ywmax = 3

    sroCoordinates = [
        [1, 0],
        [1, 2],
        [2, 2],
        [2, 0],
        [2, 1],
        [3, 1],
        [3, 0],
        [2.5, 2]
    ]

    # = -1
    sruCoordinates = [
        [0, -1],
        [0, 1],
        [1, 1],
        [1, -1],
        [1, 0],
        [2, 0],
        [2, -1],
        [1.5, 1]
    ]

    normalizedCoordinates = normalize(
        sruCoordinates, xwmin, xwmax, ywmin, ywmax)

    print("normalized:")
    for i in range(len(vertices)):
        print(
            f'{vertices[i]}: ({normalizedCoordinates[i][0]},{normalizedCoordinates[i][1]})')
