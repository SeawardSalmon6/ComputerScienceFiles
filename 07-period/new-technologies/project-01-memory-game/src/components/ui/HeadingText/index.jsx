import { Text } from "react-native";

import styles from "./styles";

export function HeadingText({ style, children }) {
  return <Text style={{ ...styles.headingText, ...style }}>{children}</Text>;
}
