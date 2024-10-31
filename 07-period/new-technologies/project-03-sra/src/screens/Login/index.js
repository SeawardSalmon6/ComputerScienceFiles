import styles from "@/screens/Login/styles";
import { Input } from "@/components/Input";
import { Form } from "@/components/Form";
import { Button } from "@/components/Button";
import { Text, View } from "react-native";
import { LoginLayout } from "@/screens/Login/components/LoginLayout";
import { useAppNavigation } from "@/hooks/useAppNavigation";
import { Controller, useForm } from "react-hook-form";

export function LoginScreen() {
  const {
    formState: { errors },
    control,
  } = useForm({ mode: "onChange" });
  const { getGoTo } = useAppNavigation();

  return (
    <LoginLayout
      title="olá, que bom ter você aqui"
      errors={errors.email ? [errors.email] : []}
    >
      <Form>
        <Controller
          control={control}
          name="email"
          rules={{ validate: (value) => console.log(value) || "error" }}
          render={({ field: { value, onChange, onBlur } }) => (
            <Input
              type="email"
              label="e-mail"
              value={value}
              onChange={onChange}
              onBlur={onBlur}
            />
          )}
        />
        <Controller
          control={control}
          name="password"
          render={({ field: { value, onChange, onBlur } }) => (
            <Input
              type="password"
              label="senha"
              value={value}
              onChange={onChange}
              onBlur={onBlur}
            />
          )}
        />
        <View style={styles.linksContainer}>
          <Text
            style={styles.link}
            onPress={getGoTo("ForgotPassword", { backTo: "Login" })}
          >
            esqueceu a senha? clique aqui
          </Text>
          <Text
            style={styles.link}
            onPress={getGoTo("Register", { backTo: "Login" })}
          >
            ainda não tem conta? clique aqui
          </Text>
        </View>
        <Button onPress={getGoTo("Home")}>entrar</Button>
      </Form>
    </LoginLayout>
  );
}
