import { Card } from "@/components/Card";
import { Layout } from "@/components/Layout";
import { useAppNavigation } from "@/hooks/useAppNavigation";
import styles from "@/screens/Login/components/LoginLayout/styles";
import { useRoute } from "@react-navigation/native";
import { Image, Pressable, Text } from "react-native";

export function LoginLayout({
  title,
  subtitle,
  showCardIcon = true,
  titleStyle,
  children,
  errors,
}) {
  const { params } = useRoute();
  const { backTo } = params ?? {};
  const { getGoTo, goBack } = useAppNavigation();

  return (
    <Layout
      rootStyle={styles.root}
      contentContainerStyle={styles.contentContainer}
      statusBarStyle="light"
    >
      {backTo !== undefined && (
        <Pressable
          onPress={backTo === null ? goBack : getGoTo(backTo)}
          style={styles.backButton}
        >
          <Image
            style={styles.backIcon}
            resizeMode="contain"
            source={require("@/assets/images/back.png")}
          />
        </Pressable>
      )}
      <Card
        containerStyle={styles.cardContainer}
        titleContainerStyle={styles.titleContainer}
        title={title}
        subtitle={subtitle}
        titleStyle={titleStyle}
      >
        {showCardIcon && (
          <Image
            style={styles.cardIcon}
            resizeMode="contain"
            source={require("@/assets/images/srazinho.png")}
          />
        )}
        {children}
        {errors &&
          errors.map((error) => (
            <Text key={error} style={styles.errorMessage}>
              {error}
            </Text>
          ))}
        <Image
          style={[styles.sraLogo]}
          resizeMode="contain"
          source={require("@/assets/icon.png")}
        />
      </Card>
    </Layout>
  );
}
