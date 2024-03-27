import { Text } from "react-native";

import styles from "./styles";

export function BodyText({ style, children }) {
  return <Text style={{ ...styles.bodyText, ...style }}>{children}</Text>;
}
