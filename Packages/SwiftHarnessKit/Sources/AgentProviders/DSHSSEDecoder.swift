import Foundation

enum DSHSSEDecoderError: Error, Equatable {
    case invalidUTF8
}

struct DSHSSEDecoder: Sendable {
    private var buffer = Data()

    mutating func append(_ data: Data) throws -> [String] {
        buffer.append(data)
        var events: [String] = []

        while let boundary = Self.eventBoundary(in: buffer) {
            let eventData = buffer.prefix(boundary.lowerBound)
            buffer.removeSubrange(..<boundary.upperBound)
            guard let event = String(data: eventData, encoding: .utf8) else {
                throw DSHSSEDecoderError.invalidUTF8
            }

            let dataLines = event
                .split(whereSeparator: \.isNewline)
                .compactMap { line -> String? in
                    guard line.hasPrefix("data:") else { return nil }
                    let value = line.dropFirst(5)
                    return value.first == " " ? String(value.dropFirst()) : String(value)
                }
            if !dataLines.isEmpty {
                events.append(dataLines.joined(separator: "\n"))
            }
        }
        return events
    }

    private static func eventBoundary(in data: Data) -> Range<Data.Index>? {
        let lf = data.range(of: Data([0x0A, 0x0A]))
        let crlf = data.range(of: Data([0x0D, 0x0A, 0x0D, 0x0A]))
        switch (lf, crlf) {
        case (.none, .none): return nil
        case (.some(let range), .none), (.none, .some(let range)): return range
        case (.some(let left), .some(let right)):
            return left.lowerBound < right.lowerBound ? left : right
        }
    }
}
